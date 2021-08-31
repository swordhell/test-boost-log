#include "A.hpp"

void A::SaySomeVerse()
{
	BOOST_LOG_SEV(scl, debug) << __FUNCTION__ << ":" << __LINE__ << " 富贵不知乐业，贫穷难耐凄凉。身后有余忘缩手，眼前无路想回头。\n";
}
