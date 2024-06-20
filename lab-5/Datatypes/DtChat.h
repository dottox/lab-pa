#ifndef DTCHAT_H
#define DTCHAT_H

#include "../ICollection/interfaces/ICollectible.h"

#include <string>
using namespace std;

class ICollectible;

struct DtChat : public ICollectible
{
  private:
    string interesado;
    int propiedad;
    int cantMensajes;

  public:
    // Constructor
    DtChat(string, int, int);
    
    // Getters
    string getInteresado();
    int getPropiedad();
    int getCantMensajes();

    // Destructor
    ~DtChat();
};

#endif