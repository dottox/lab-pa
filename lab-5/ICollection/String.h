#include "interfaces/ICollectible.h"
#include "interfaces/OrderedKey.h"

/**
 *  Implementación simple del datatype String que hereda tanto de ICollectible
 *  como de HashedKey
 */

#ifndef _STRING_H
#define	_STRING_H

class String: public ICollectible, public OrderedKey
{
private:
    char *s;
public:
    // construye el Datatype a partir de un puntero a caracter
    String(const char *s = "");
    
    // da el valor del string
    const char *getValue() const;
    
    ComparisonRes compare(OrderedKey *k) const;
    
    virtual ~String();
    
};

#endif	/*_STRING_H */

