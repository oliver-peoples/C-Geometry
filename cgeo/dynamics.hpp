#pragma once

#include <hmath.hpp>
#include <cgeo_core.hpp>
#include <cgeo/units.hpp>
#include <cgeo/hmath.hpp>

namespace cgeo
{
    template <typename T> class Particle : public PointE3<T>
    {
    public:
        T mass = 0 * unit::kilogram;
        T charge = 0 * unit::coulomb;
        hmath::Vector3<T> velocity = { 0 * (unit::meter / unit::second),0 * (unit::meter / unit::second),0 * (unit::meter / unit::second) };

        using PointE3<T>::PointE3;

        Particle() {}
        ~Particle() {}
    };

    template <typename T> class ParticleCloud
    {
    private:
        std::vector<Particle<T>> particles;

    public:
        
        ParticleCloud() {}
        ~ParticleCloud() {}

        void addParticle(Particle<T>& particle)
        {
            this->particles.push_back(particle);
        }

        Particle<T>& operator[](size_t idx)
        {
            return this->particles[idx];
        }
    };
    
    // template <typename T> class Propagator
    // {
    // private:
    //     T dt;
    // public:
    //     Propagator() {}
    //     ~Propagator() {}
    // };
}
