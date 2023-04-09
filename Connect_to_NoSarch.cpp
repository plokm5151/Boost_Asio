#include<iostream>
#include<boost/asio.hpp>

int main(){
	boost::asio::io_context io_context;
	boost::asio::ip::tcp::resolver resolver{ io_context };
	boost::asio::ip::tcp::socket socket{ io_context };
	try {
		auto endpoints = resolver.resolve("www.nostarch.com","http");
		const auto connected_endpoint = boost::asio::connect(socket,
			endpoints);
		std::cout << connected_endpoint;
	}catch(boost::system::system_error& se){
		std::cerr << "Erro: "<< se.what() << std::endl;
	}
}

