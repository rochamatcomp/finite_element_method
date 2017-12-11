/**
 * Asserts by exceptions.
 */

#include <stdexcept>

/*
  exception
    logic_error
        domain_error
        invalid_argument
        length_error
        out_of_range
    runtime_error
        range_error
        overflow_error
        underflow_error
 */

#ifdef NDEBUG
#define range_assert(EXPRESSION) ((void)0)
#else
#define range_assert(EXPRESSION) ((EXPRESSION) ? (void)0 : _assert(#EXPRESSION, __FILE__, __LINE__))
#endif

inline void _assert(const char* expression, const char* file, int line)
{
  char message[100];
  sprintf(message, "Assertion failed, '%s'. file '%s' line '%d'.", expression, file, line);
  throw std::out_of_range(message);
}
