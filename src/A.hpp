#pragma once
#include <boost/log/trivial.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>
namespace logging = boost::log;
using namespace logging::trivial;
namespace src = boost::log::sources;


class A
{
public:
	A() = default;
	~A() = default;

	void SaySomeVerse();

private:
	src::severity_channel_logger<severity_level, std::string> scl;
};