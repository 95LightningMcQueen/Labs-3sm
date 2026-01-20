#include "Music.h"


const char* TypeOfGenre(AllGenre g)
{
    switch (g)
    {
    case Song:     return "Song";
    case Opera:    return "Opera";
    case Simphony: return "Simphony";
    default:       return "Other";
    }
}

Music::Music() : id(0) {}

Music::Music(int32_t id_) : id(id_) {}

Music::Music(const Music& other) : id(other.id) {}

Music::~Music() {}

int32_t Music::getId() const { return id; }

void Music::print(std::ostream& os) const
{
    os << "Music id: " << id;
}

MusicalComposition::MusicalComposition() : Music(0), nameCompos(nullptr), genre(Other), year(0) {}

MusicalComposition::MusicalComposition(int32_t id_, AllGenre g, int year_) : Music(id_), nameCompos(nullptr), genre(g), year(year_) {}

MusicalComposition::MusicalComposition(const MusicalComposition& other) : Music(other), nameCompos(nullptr), genre(other.genre), year(other.year)
{
    if (other.nameCompos) 
    {
        size_t len = std::strlen(other.nameCompos);
        nameCompos = new char[len + 1];
        std::strcpy(nameCompos, other.nameCompos);
    }
}

MusicalComposition::~MusicalComposition()
{
    delete[] nameCompos;
}

MusicalComposition& MusicalComposition::operator=(const MusicalComposition& other)
{
    if (this == &other) { return *this; }
    delete[] nameCompos;
    nameCompos = nullptr;
    if (other.nameCompos) 
    {
        size_t len = std::strlen(other.nameCompos);
        nameCompos = new char[len + 1];
        std::strcpy(nameCompos, other.nameCompos);
    }
    genre = other.genre;
    return *this;
}

void MusicalComposition::setGenre(AllGenre g)
{
    genre = g;
}

AllGenre MusicalComposition::getGenre() const
{
    return genre;
}

int32_t MusicalComposition::getYear() const
{
    return year;
}

std::ostream& operator<<(std::ostream& os, const MusicalComposition& a)
{
    os << " ID: " << a.id << ", Name of Composition: " << (a.nameCompos ? a.nameCompos : "NULL") << ", Genre: " << TypeOfGenre(a.genre) << ", Year of creation: " << a.year;
    return os;
}