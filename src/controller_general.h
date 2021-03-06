#pragma once

#include <vector>
#include <SFML/Window/Event.hpp>

namespace cw
{
	namespace util
	{
		class GeneralListener;

		class GeneralController
		{
		public:
			virtual ~GeneralController() {}
			void addGeneralListener( GeneralListener& );

		protected:
			void updateGeneralListeners( const sf::Event& );

		private:
			std::vector< GeneralListener* > m_generalListeners;
		};
	}
}