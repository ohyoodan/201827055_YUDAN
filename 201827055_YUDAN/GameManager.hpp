#pragma once
#include "Player.hpp"
#include  "Enemyfactory.hpp"
#include "bullet.hpp"
#include "vec.hpp"
#include "Window_Render.hpp"
#include <chrono>






namespace STRIKERS_YUHAN {

	class GameManager {
		bool GameStart = false;
	public: 
		GameManager() {

		}
		~GameManager() {

		}
	public: enum GameTitle
	{
		Start = 0, End = 1, TitDefault = 2

	};

	public: enum GameStart {
		live = 0, Dead =1 , StaDefault = 2

	};
	public: enum GameEnd {
		Good = 0, Bad = 1, EndDefault = 2

	};

		 
		  
		  


	};
}