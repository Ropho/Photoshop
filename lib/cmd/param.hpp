#ifndef PARAM_HPP
#define PARAM_HPP

namespace param {

class Param {

    public:
        Param () {

        }

        void add (void *param) {
            params_.push_back (param);
        }

        std::vector <void *>& get (void) {
            return params_;
        }

    private:
        std::vector <void *> params_ {};
};

}
#endif