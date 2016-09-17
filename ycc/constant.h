#ifndef CONSTANT_H_
#define CONSTANT_H_

#include "token.h"

namespace ycc
{
    enum class ConstantKind
    {
        INT_CONSTANT,
        REAL_CONSTANT,
        CHAR_CONSTANT,
        BOOL_CONSTANT,
        STRING_CONSTANT
    };

    class Constant
    {
      public:
        explicit            Constant(ConstantKind kind, const TokenLocation &loc);
        virtual             ~Constant() = default;
        ConstantKind        getKind() const;
        virtual Token       makeToken() const = 0;
        virtual void        dump() const = 0;

      protected:
        const ConstantKind  constantKind_;
        TokenLocation       tokenLocation_;

    };

    class IntConstant : public Constant
    {
      public:
        explicit            IntConstant(long l, const TokenLocation &loc);
        virtual Token       makeToken() const override;
        virtual void        dump() const override;
        long                getValue() const;

      private:
        long                value_;
    };

    class RealConstant : public Constant
    {
      public:
        explicit            RealConstant(double d, const TokenLocation &loc);
        virtual Token       makeToken() const override;
        virtual void        dump() const override;
        double              getValue() const;

      private:
        double              value_;
    };

    class CharConstant : public Constant
    {
      public:
        explicit            CharConstant(char c, const TokenLocation &loc);
        virtual Token       makeToken() const override;
        virtual void        dump() const override;
        char                getValue() const;

      private:
        char                value_;
    };

    class BoolConstant : public Constant
    {
      public: 
        explicit            BoolConstant(bool b, const TokenLocation &loc);
        virtual Token       makeToken() const override;
        virtual void        dump() const override;
        bool                getValue() const;

      private:
        bool                value_;
    };

    class StringConstant: public Constant
    {
      public:
        explicit            StringConstant(const std::string &str, const TokenLocation &loc);
        virtual Token       makeToken() const override;
        virtual void        dump() const override;
        const std::string&  getValue() const;

      private:
        std::string         value_;
    };

    inline ConstantKind Constant::getKind() const
    {
        return constantKind_;
    }

    inline long IntConstant::getValue() const
    {
        return value_;
    }

    inline double RealConstant::getValue() const
    {
        return value_;
    }

    inline char CharConstant::getValue() const
    {
        return value_;
    }

    inline bool BoolConstant::getValue() const
    {
        return value_;
    }

    inline const std::string& StringConstant::getValue() const
    {
        return value_;
    }

    // TODO:
    // constant operatation. (consider to use operator overload)
}


#endif
