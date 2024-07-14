#ifndef NEO_WEAPON_ZR68_L_H
#define NEO_WEAPON_ZR68_L_H
#ifdef _WIN32
#pragma once
#endif

#include "cbase.h"
#include "npcevent.h"
#include "in_buttons.h"

#ifdef CLIENT_DLL
#include "c_neo_player.h"
#else
#include "neo_player.h"
#endif

#include "weapon_neobasecombatweapon.h"

#ifdef CLIENT_DLL
#define CWeaponZR68L C_WeaponZR68L
#endif

class CWeaponZR68L : public CNEOBaseCombatWeapon
{
	DECLARE_CLASS(CWeaponZR68L, CNEOBaseCombatWeapon);
public:
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();

#ifdef GAME_DLL
	DECLARE_ACTTABLE();
#endif

	CWeaponZR68L();

	void	ItemPostFrame(void);
	virtual void	PrimaryAttack(void) OVERRIDE { if (!ShootingIsPrevented()) { BaseClass::PrimaryAttack(); } }
	virtual void	SecondaryAttack(void) OVERRIDE { if (!ShootingIsPrevented()) { BaseClass::SecondaryAttack(); } }
	void	AddViewKick(void);
	void	DryFire(void);

	virtual NEO_WEP_BITS_UNDERLYING_TYPE GetNeoWepBits(void) const { return NEO_WEP_ZR68_L | NEO_WEP_SCOPEDWEAPON; }
	virtual int GetNeoWepXPCost(const int neoClass) const { return 0; }

	virtual float GetSpeedScale(void) const { return 145.0 / 170.0; }

	virtual Vector GetMinConeHip() const OVERRIDE { static Vector cone = VECTOR_CONE_4DEGREES; return cone; }
	virtual Vector GetMaxConeHip() const OVERRIDE { static Vector cone = VECTOR_CONE_7DEGREES; return cone; }
	virtual Vector GetMinConeAim() const OVERRIDE { static Vector cone = VECTOR_CONE_PRECALCULATED; return cone; }
	virtual Vector GetMaxConeAim() const OVERRIDE { static Vector cone = VECTOR_CONE_2DEGREES; return cone; }

	Activity	GetPrimaryAttackActivity(void);

protected:
	virtual float GetFastestDryRefireTime() const OVERRIDE { return 0.2f; }

private:
	CWeaponZR68L(const CWeaponZR68L &other);
};

#endif // NEO_WEAPON_ZR68_L_H
