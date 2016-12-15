#ifndef NS_ENUM
	#if (__cplusplus && __cplusplus >= 201103L && (__has_extension(cxx_strong_enums) || __has_feature(objc_fixed_enum))) || (!__cplusplus && __has_feature(objc_fixed_enum))
	  #define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
	  #if (__cplusplus)
	    #define NS_OPTIONS(_type, _name) _type _name; enum : _type
	  #else
	    #define NS_OPTIONS(_type, _name) enum _name : _type _name; enum _name : _type
	  #endif
	#else
	  #define NS_ENUM(_type, _name) _type _name; enum
	  #define NS_OPTIONS(_type, _name) _type _name; enum
	#endif
#endif

#if !defined (OF_SIZEOF_VOIDP)
	#define OF_SIZEOF_VOIDP __SIZEOF_POINTER__
#endif

#if !defined(NSINTEGER_DEFINED) && !defined(CGFLOAT_DEFINED)
	typedef	intptr_t	NSInteger;
	typedef	uintptr_t	NSUInteger;
	#define NSIntegerMax  INTPTR_MAX
	#define NSIntegerMin  INTPTR_MIN
	#define NSUIntegerMax UINTPTR_MAX
	#if OF_SIZEOF_VOIDP == 8
		#define CGFLOAT_IS_DBL  1
		typedef double          CGFloat;
		#define CGFLOAT_MIN	DBL_MIN
		#define CGFLOAT_MAX	DBL_MAX
	#else
		typedef float           CGFloat;
		#define CGFLOAT_MIN	FLT_MIN
		#define CGFLOAT_MAX	FLT_MAX
	#endif
#endif

#ifndef kCFSocketError
	#define kCFSocketError -1L
#endif

#ifndef MAX
	#define MAX(a,b) \
	       ({__typeof__(a) _MAX_a = (a); __typeof__(b) _MAX_b = (b);  \
	         _MAX_a > _MAX_b ? _MAX_a : _MAX_b; })
	#define	DEFINED_MAX
#endif

#ifndef MIN
	#define MIN(a,b) \
	       ({__typeof__(a) _MIN_a = (a); __typeof__(b) _MIN_b = (b);  \
	         _MIN_a < _MIN_b ? _MIN_a : _MIN_b; })
	#define	DEFINED_MIN
#endif		