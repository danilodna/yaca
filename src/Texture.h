#ifndef TEXTURE_H_
#define TEXTURE_H_


class Texture
{
private:
    int m_id;
public:
    Texture() = default;
    ~Texture() = default;

    int getID() const { return m_id; };
    int setID(const int id) { m_id = id; };
};

#endif // TEXTURE_H_