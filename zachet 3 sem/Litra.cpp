#include "Litra.h"


const char* GenreType(Genres g)
{
	switch (g)
	{
	case Roman: return "Roman";
	case Povest: return "Povest";
	case Poema: return "Poema";
	default: return "Other";
	}
}

Litra::Litra(int id) : id(id) {}

Litra::Litra(const Litra& other) : id(other.id) {}

Litra::Litra(Litra&& other) noexcept : id(std::move(other.id)) {}

Litra& Litra::operator=(const Litra& other)
{
	if (this == &other)
	{
		return *this;
	}
	this->id = other.id;
	return *this;
}

Litra& Litra::operator=(Litra&& other) noexcept
{
	if (this == &other)
	{
		return *this;
	}
	this->id = std::move(other.id);
	return *this;
}

bool Litra::operator==(const Litra& other) const { return this->id == other.id; }

int Litra::GetId() const { return id; }

void Litra::Print(std::ostream& os)
{
	os << "\nLitra id : " << GetId();
}

LitraPro::LitraPro(int id, const char* nameCompos, Genres genre, int year) : Litra(id), genre(genre), year(year)
{
	this->nameCompos = new char[strlen(nameCompos) + 1];
	std::strcpy(this->nameCompos, nameCompos);
}

LitraPro::LitraPro(const LitraPro& other) : Litra(other), genre(other.genre), year(other.year)
{
	nameCompos = new char[strlen(other.nameCompos) + 1];
	std::strcpy(nameCompos, other.nameCompos);
}

LitraPro::LitraPro(LitraPro&& other) noexcept : Litra(std::move(other)), genre(std::move(other.genre)), year(std::move(other.year)), nameCompos(other.nameCompos)
{
	other.nameCompos = nullptr;
}

LitraPro& LitraPro::operator=(const LitraPro& other)
{
	if (this == &other)
	{
		return *this;
	}
	Litra::operator=(other);
	genre = other.genre;
	if (nameCompos)
	{
		delete[] nameCompos;
	}
	nameCompos = new char[strlen(other.nameCompos) + 1];
	std::strcpy(nameCompos, other.nameCompos);
	return *this;
}

LitraPro& LitraPro::operator=(LitraPro&& other) noexcept
{
	if (this == &other)
	{
		return *this;
	}
	Litra::operator=(std::move(other));
	genre = other.genre;
	if (nameCompos)
	{
		delete[] nameCompos;
	}
	nameCompos = other.nameCompos;
	other.nameCompos = nullptr;
	return *this;
}

const char* LitraPro::GetNameCompos() const { return nameCompos; }

Genres LitraPro::GetGenre() const { return genre; }

int LitraPro::GetYear() const { return year; }

LitraPro::~LitraPro() { delete[] nameCompos; };

bool LitraPro::operator==(const LitraPro& other) const { return Litra::operator==(other) && genre == other.genre && year == other.year && std::strcmp(nameCompos, other.nameCompos) == 0; }

void LitraPro::Print(std::ostream& os)
{
	os << "\nid: " << GetId() << "\nkomposition : " << (nameCompos ? nameCompos : "Unknown") << "\ngenre: " << GenreType(genre) << "\nyear: " << year;
}