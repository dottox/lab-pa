#ifndef _IKEY_H
#define	_IKEY_H

class IKey
{
public:
    /**
     *  Retorna true sii this es igual al argumento
     */
    virtual bool equals(IKey *) const = 0;
    
    virtual ~IKey();
};

#endif	/* _IKEY_H */

