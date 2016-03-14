#ifndef ROYAUME_H
#define ROYAUME_H

#include <vector>
#include "Case.h"

class Royaume
{
    public:
        Royaume();
        virtual ~Royaume();

        Case& get(int i, int j);
        const Case& get(int i, int j) const;
        int getLargeur() const;
        int getHauteur() const;

    private:
        std::vector<std::vector<Case> > m_cases;
};

#endif // ROYAUME_H
