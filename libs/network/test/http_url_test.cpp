//            Copyright (c) Glyn Matthews 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#define BOOST_TEST_MODULE HTTP URL Test
#include <boost/config/warning_disable.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/network/uri/http/uri.hpp>
#include <boost/mpl/list.hpp>
#include <boost/range/algorithm/equal.hpp>

using namespace boost::network;

typedef boost::mpl::list<
    tags::default_string
    , tags::default_wstring
> tag_types;


BOOST_AUTO_TEST_CASE_TEMPLATE(http_url_test, T, tag_types) {
    typedef uri::http::basic_uri<T> uri_type;
    typedef typename uri_type::string_type string_type;

    const std::string url("http://www.boost.org/");
    const std::string scheme("http");
    const std::string host("www.boost.org");
    const std::string port("80");
    const std::string path("/");

    uri_type instance(string_type(boost::begin(url), boost::end(url)));
    BOOST_CHECK(boost::equal(uri::scheme(instance), scheme));
    BOOST_CHECK(boost::equal(uri::host(instance), host));
    BOOST_CHECK(boost::equal(uri::port(instance), port));
    BOOST_CHECK(boost::equal(uri::path(instance), path));
    BOOST_CHECK(uri::is_valid(instance));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(full_http_url_test, T, tag_types) {
    typedef uri::basic_uri<T> uri_type;
    typedef typename uri_type::string_type string_type;

    const std::string url("http://user:password@www.boost.org:8000/path?query#fragment");
    const std::string scheme("http");
    const std::string user_info("user:password");
    const std::string host("www.boost.org");
    const std::string port("8000");
    const std::string path("/path");
    const std::string query("query");
    const std::string fragment("fragment");

    uri_type instance(string_type(boost::begin(url), boost::end(url)));
    BOOST_CHECK(uri::is_valid(instance));
    BOOST_CHECK(boost::equal(uri::scheme(instance), scheme));
    BOOST_CHECK(boost::equal(uri::user_info(instance), user_info));
    BOOST_CHECK(boost::equal(uri::host(instance), host));
    BOOST_CHECK(boost::equal(uri::port(instance), port));
    BOOST_CHECK(boost::equal(uri::path(instance), path));
    BOOST_CHECK(boost::equal(uri::query(instance), query));
    BOOST_CHECK(boost::equal(uri::fragment(instance), fragment));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(https_url_test, T, tag_types) {
    typedef uri::http::basic_uri<T> uri_type;
    typedef typename uri_type::string_type string_type;

    const std::string url("http://www.boost.org/");
    const std::string scheme("https");
    const std::string host("www.boost.org");
    const std::string port("443");
    const std::string path("/");

    uri_type instance(string_type(boost::begin(url), boost::end(url)));
    BOOST_CHECK(boost::equal(uri::scheme(instance), scheme));
    BOOST_CHECK(boost::equal(uri::host(instance), host));
    BOOST_CHECK(boost::equal(uri::port(instance), port));
    BOOST_CHECK(boost::equal(uri::path(instance), path));
    BOOST_CHECK(uri::is_valid(instance));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(invalid_http_url_test, T, tag_types) {
    typedef uri::basic_uri<T> uri_type;
    typedef typename uri_type::string_type string_type;

    uri_type instance(string_type(boost::begin(url), boost::end(url)));
    BOOST_CHECK(!uri::is_valid(instance));
}