#include "Image.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
using namespace std ;

//////////Change The Followoing Variables to choose different pgm operation test cases 
string pgm_image_name = "crowd.pgm";
string mask_name = "Lenna_hat_mask.pgm" ;


MPHFAR001::Image testing_image(pgm_image_name) , mask(mask_name)  , buffer ;

TEST_CASE("Testing For Adding", "[add]") {
    buffer << "unit_test_results/add_test.pgm";
    REQUIRE((testing_image + mask) == buffer);
}

TEST_CASE("Testing For Save", "[save]") {
    buffer << "unit_test_results/save_test.pgm";
    REQUIRE((testing_image + mask) == buffer);
    (testing_image + mask) >> "unit_test_results/save_test.pgm";
    buffer << "unit_test_results/save_test.pgm";
    REQUIRE((testing_image + mask) == buffer);
}

TEST_CASE("Testing For Subtracting", "[subtract]") {
    buffer << "unit_test_results/subtract_test.pgm";
    REQUIRE((testing_image - mask) == buffer);
}

TEST_CASE("Testing For Inverting", "[invert]") {
    buffer << "unit_test_results/invert_test.pgm";
    REQUIRE(!mask == buffer);
}

TEST_CASE("Testing For Masking", "[mask]") {
    buffer << "unit_test_results/mask_test.pgm";
    REQUIRE((testing_image / mask) == buffer);
}

TEST_CASE("Testing For Threshold", "[threshold]") {
    buffer << "unit_test_results/200_threshold_test.pgm";
    REQUIRE((testing_image * 200) == buffer);
}

