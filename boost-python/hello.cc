char const *hello() { return "hello, world"; }

#include <boost/python.hpp>

BOOST_PYTHON_MODULE(hello) {
  using namespace boost::python;
  def("hello", hello);
}
