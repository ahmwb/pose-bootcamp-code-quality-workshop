#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include "address_book.hpp"

TEST_CASE("entries can be added and removed")
{
	address_book ab;
	CHECK_FALSE(ab.has_entry("Jane Doe"));
	ab.add_entry("Jane Doe");
	CHECK(ab.has_entry("Jane Doe"));

	ab.set_phone_number("Jane Doe", 23);
	CHECK(ab.get_phone_number( "Jane Doe") == 23);

	ab.remove_entry("Jane Doe");
	CHECK_FALSE(ab.has_entry("Jane Doe"));

char	long_entry[] = "A012345679 B012345679 C012345679 D012345679 E012345679 F012345679 G012345679 H012345679 I012345679 "
		       "A012345679 B012345679 C012345679 D012345679 E012345679 F012345679 G012345679 H012345679 I012345679 "
		       "A012345679 B012345679 C012345679 D012345679 E012345679 F012345679 G012345679 H012345679 I012345679 ";

	CHECK_THROWS( ab.add_entry(long_entry) );
	CHECK_FALSE(ab.has_entry(long_entry));

	ab.add_entry("alpha john");
	CHECK(ab.has_entry("alpha john") );
	CHECK(ab.has_entry("Alpha John") );

using namespace std::chrono_literals;
	ab.set_birthday("alpha john", std::chrono::month_day(std::chrono::February, 29d) );
	CHECK( ab.get_birthday("alpha john") == std::chrono::month_day(std::chrono::February, 29d) );

}
