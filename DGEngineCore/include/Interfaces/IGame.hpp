#ifndef DGENGINE_INTERFACES_IGAME_HPP
#define DGENGINE_INTERFACES_IGAME_HPP

#include "Common.hpp"

namespace dge {

	class DGE_API IGame {

	public:
		IGame() {}
		virtual ~IGame() {}

		virtual void init() = 0;
		virtual void input() = 0;
		virtual void update(double dt) = 0;
		virtual void render(double alpha) = 0;


	};

}

#endif // !DGENGINE_INTERFACES_IGAME_HPP

