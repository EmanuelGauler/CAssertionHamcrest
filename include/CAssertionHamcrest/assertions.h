#ifndef ASSERTIONS_H
#define ASSERTIONS_H
struct Assertion
{
   Assertion( T t ) : actual( t ) {}
   bool is( Matcher<T> const&matcher ) const {
      return matcher.match( actual );
   }
   bool is( Matcher<T>&&matcher ) const {
      return is( matcher );
   }
   protected:
   T actual;
};

template<typename T>
Assertion<T> that( T actual ) {
   return Assertion<T>( actual );
}
#endif //ASSERTIONS_H
