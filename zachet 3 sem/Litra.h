#ifndef LITRA_H
#define LITRA_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdint>


enum Genres { Roman, Povest, Poema, Other };

class Litra
{
protected:
	int id; //я забыл, что тут конст инт должен быть не бейте, пожалуйста :с <3
public:
	Litra(int id = 0);
	Litra(const Litra& other);
	Litra(Litra&& other) noexcept;
	Litra& operator=(const Litra& other);
	Litra& operator=(Litra&& other) noexcept;
	int GetId() const;
	bool operator==(const Litra& other) const;
	virtual ~Litra() = default;
	virtual void Print(std::ostream& os) = 0;
};

class LitraPro : Litra
{
protected:
	char* nameCompos;
	Genres genre; 
	const int year;
public:
	LitraPro(int id, const char* nameCompos, Genres genre, int year);
	LitraPro(const LitraPro& other);
	LitraPro(LitraPro&& other) noexcept;
	LitraPro& operator=(const LitraPro& other);
	LitraPro& operator=(LitraPro&& other) noexcept;
	bool operator==(const LitraPro& other) const;
	~LitraPro();
	const char* GetNameCompos() const;
	Genres GetGenre() const;
	int GetYear() const;
	friend std::ostream& operator << (std::ostream& os, const LitraPro& txt);
	void Print(std::ostream& os) override;
};


#endif