#pragma once
class Tiempo {
private:
	float tiempo;
	bool reset;
public:
	Tiempo();
	float GetTiempo();
	bool GetReset();

	void SetTiempo(float t);
	void SetReset(bool r);
};