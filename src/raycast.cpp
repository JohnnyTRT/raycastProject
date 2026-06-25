//this is a seperate raycast file to handle all the raycast logic and math 
#include <cstdint>
#include <cmath>
#include <maze.hpp>

class raycast{
	public:
		//constructor
		raycast();
		//rebder function
		void render(
			int screenWidth,
			int screenHeight,
			uint32_t* buffer,
			double posX,
			double posY,
			double dirX,
			double dirY,
			double planeX,
			double planeY,
			maze gameMap);
	private:
		double rayX, rayY;
		double deltaX, deltaY;
		double cameraDistribution;
		bool hit;
		bool isVerticalWall;
		double cellX, cellY;
		double sideDistX, sideDistY;
		int stepX, stepY;
		double perpWallDist;

	
};

void raycast::render(	int screenWidth,
		int screenHeight,
		uint32_t* buffer,
		double posX,
		double posY,
		double dirX,
		double dirY,
		double planeX,
		double planeY,
		maze gameMap){



	for(auto i{0}; i < screenWidth; i++){
		cameraDistribution = ((2.0*i)/screenWidth) - 1.0;
		rayX = dirX + planeX * cameraDistribution;
		rayY = dirY + planeY * cameraDistribution;


		cellX = std::floor(posX), cellY = std::floor(posY);

		deltaX = std::abs(1/rayX), deltaY = std::abs(1/rayY);

		hit = false;

		if(rayX < 0){
			stepX = -1;
			sideDistX = (posX - cellX) * deltaX;
		}else{
			stepX = 1;
			sideDistX = (cellX + 1.0 - posX) * deltaX;
		}

		if(rayY < 0){
			stepY = -1;
			sideDistY = (posY - cellY) * deltaY;
		}else{
			stepY = 1;
			sideDistY = (cellY + 1.0 - posY) * deltaY;

		}

		while(!hit){
			if(sideDistX < sideDistY){
				sideDistX += deltaX;
				cellX += stepX;
				isVerticalWall = true;
			}else{
				sideDistY += deltaY;
				cellY += stepY;
				isVerticalWall = false;
			}

			if(gameMap.isWall(cellX, cellY)){
				hit = true;
			}

		}

		if(isVerticalWall){
			perpWallDist = sideDistX - deltaX;
		}else{
			perpWallDist = sideDistY - deltaY;
		}

		int lineHeight = (int)(screenHeight / perpWallDist);

		int lineStart = -lineHeight / 2 + screenHeight / 2;
		if(lineStart < 0) lineStart = 0;

		int lineEnd = lineHeight / 2 + screenHeight / 2;
		if(lineEnd >= screenHeight) lineEnd = screenHeight - 1;	

		for(int j = lineStart; j < lineEnd; j++){
			//uploading Red for testing
			buffer[j * screenWidth + i] = 0xFFFF0000;
		}

	}
}
