#ifndef PYTHONIC_TYPES_VECTORIZABLE_TYPE_HPP
#define PYTHONIC_TYPES_VECTORIZABLE_TYPE_HPP
namespace pythonic {

namespace operator_ {
  namespace proxy {
    struct mod;
  }
}

namespace numpy {
  namespace proxy {
    struct mod;
    struct logaddexp2;
    struct ldexp;
    struct isfinite;
    struct isinf;
    struct fix;
    struct isnan;
    struct isposinf;
    struct rint;
    struct round;
    struct round_;
    struct signbit;
    struct nan_to_num;
    struct asarray_chkfinite;
  }
}

namespace types {

template<class T>
  struct is_vectorizable {
    static const bool value = std::is_fundamental<T>::value and not std::is_same<T, bool>::value;
  };

template<class O>
  struct is_vector_op {

    // vectorize everything but these ops. They require special handling for
    // vectorization, and SG did not invest enough time in those
    static const bool value = not std::is_same<O, numpy::proxy::mod>::value and
                              not std::is_same<O, operator_::proxy::mod>::value and
                              not std::is_same<O, numpy::proxy::logaddexp2>::value and
                              // Return type for generic function should be generic
                              not std::is_same<O, numpy::proxy::ldexp>::value and
                              not std::is_same<O, numpy::proxy::isfinite>::value and
                              not std::is_same<O, numpy::proxy::fix>::value and
                              not std::is_same<O, numpy::proxy::isinf>::value and
                              not std::is_same<O, numpy::proxy::isnan>::value and
                              not std::is_same<O, numpy::proxy::isposinf>::value and
                              not std::is_same<O, numpy::proxy::rint>::value and
                              not std::is_same<O, numpy::proxy::round>::value and
                              not std::is_same<O, numpy::proxy::round_>::value and
                              not std::is_same<O, numpy::proxy::signbit>::value and
                              // conditional processing doesn't permit SIMD
                              not std::is_same<O, numpy::proxy::nan_to_num>::value and
                              not std::is_same<O, numpy::proxy::asarray_chkfinite>::value;
  };

}

}
#endif
