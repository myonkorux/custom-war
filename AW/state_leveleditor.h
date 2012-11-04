#pragma once

#include "state.h"
#include "map.h"
#include "mapviewer.h"

#include "listener_key.h"
#include "listener_mouse.h"

#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>

namespace cw
{
	namespace state
	{
		class LevelEditor : public StateBase, public util::KeyListener, public util::MouseListener
		{
		public:
			LevelEditor();

			void createMap( int x, int y );
			void resizeMap( int width, int height );

			void setCurrentTile( const std::string& tile );

			void load( const std::string& );
			void save( const std::string& ) const;

			void host( unsigned short port = 8888 );
			void connect( sf::IpAddress& addr, unsigned short port = 8888 );

			void disconnect();

		private:
			void onKeyPressed( const sf::Event::KeyEvent& );
			void onKeyReleased( const sf::Event::KeyEvent& );

			void onMouseButtonPressed( const sf::Event::MouseButtonEvent& );
			void onMouseButtonReleased( const sf::Event::MouseButtonEvent& );
			void onMouseEntered();
			void onMouseLeft();
			void onMouseMoved( const sf::Event::MouseMoveEvent& );
			void onMouseWheelMoved( const sf::Event::MouseWheelEvent& );

			void update();
			void draw( sf::RenderTarget&, sf::RenderStates ) const;

		private:
			Map m_map;
			MapViewer m_viewer;

			std::string m_curTile;

			std::pair< bool, sf::Vector2i > m_mouse;

			// Networking test
			sf::TcpListener m_tcpListener;
			sf::TcpSocket m_tcpSocket;
			enum { LOCAL, HOST, CLIENT } m_state;
		};
	}
}