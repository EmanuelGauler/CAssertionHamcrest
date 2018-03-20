#ifndef MATCHERS_H
#define MATCHERS_H
template<typename T>
struct Matcher
{
   Matcher( T t ) : expected( t ) {}
   virtual bool match( T actual ) const = 0;
   protected:
   T expected;
};

template<typename T>
struct EqualToMatcher : public Matcher<T>
{
   EqualToMatcher( T t ) : Matcher<T>( t ) {}
   bool match( T actual ) const {
      return std::equal_to<T>( actual, this->expected );
   }
};

template<typename T>
struct LessThanMatcher : public Matcher<T>
{
   LessThanMatcher( T e ) : Matcher<T>( e ) {}
   bool match( T actual ) const {
      return std::less<T>( actual, this->expected );
   }
};
#endif //MATCHERS_H
