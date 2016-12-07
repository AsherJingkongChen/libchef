/**
 * @file   assert_wrapper.hpp
 * @deps   nope
 *
 * @author
 *   chef <191201771@qq.com>
 *     -initial release xxxx-xx-xx
 *
 * @brief
 *   �ض���debugģʽʱ��assert����Ϊ����coredump��Ϊ��stderr�����־����releaseģʽ����Ȼ����ԭ���߼�������assert��
 *
 */

#ifndef _BASE_TEST_COMMON_ASSERT_WRAPPER_HPP_
#define _BASE_TEST_COMMON_ASSERT_WRAPPER_HPP_

#include <assert.h>
#ifdef NDEBUG
#undef assert
#define assert(expr) if(!(expr)) {fprintf(stderr, "%s %s %d\n", #expr, __FILE__, __LINE__);};
#endif

#endif // _BASE_TEST_COMMON_ASSERT_WRAPPER_HPP_
