#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <cstdint>

enum AllGenre { Song, Opera, Simphony, Other };

class Music
{
protected:
    const int32_t id;
public:
    Music();
    Music(int32_t id_);
    Music(const Music& other);
    ~Music();
    int32_t getId() const;
    virtual void print(std::ostream& os) const;
};

class MusicalComposition : public Music
{
protected:
    char* nameCompos;
    AllGenre genre;
    const int32_t year;
public:
    MusicalComposition();
    MusicalComposition(int32_t id_, AllGenre g, int year_);
    MusicalComposition(const MusicalComposition& other);
    ~MusicalComposition();
    MusicalComposition& operator=(const MusicalComposition& other);
    void setGenre(AllGenre g);
    AllGenre getGenre() const;
    int32_t getYear() const;
    friend std::ostream& operator<<(std::ostream& os, const MusicalComposition& a);
};

#endif
