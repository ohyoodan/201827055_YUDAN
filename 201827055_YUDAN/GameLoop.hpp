#pragma once


#include "GameManager.hpp"

using namespace STRIKERS_YUHAN;
namespace STRIKERS_YUHAN {


	bool  GameRunning;
	class GameLoop {
	public:
		GameLoop() { GameRunning = false;  }
		~GameLoop() {}

		void GameRun() {
			GameRunning = true;
			
		}


		void Input() {

		}

		void Update() {

		}

		void Render() {


		}

		

	};


}