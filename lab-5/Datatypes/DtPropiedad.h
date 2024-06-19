#include "DtDireccion.h"

#include "../ICollection/interfaces/ICollectible.h"

struct DtDireccion;
class ICollectible;

struct DtInfo : public ICollectible
{
  private:
    int codigo;
 
    DtDireccion direccion;

  public:
    // Constructor
    DtInfo(int, int, DtDireccion);
    
    // Getters
    int getCodigo();
    int getCantMensajes();
    DtDireccion getDireccion();

    // Destructor
    ~DtInfo();
};

#endif