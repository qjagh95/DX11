#pragma once
#include "Component_Base.h"

JEONG_BEGIN

class JEONG_DLL Collider_Com : public Component_Base
{
public:
	virtual bool Init() override;
	virtual int Input(float DeltaTime) override;
	virtual int Update(float DeltaTime) override;
	virtual int LateUpdate(float DeltaTime) override;
	virtual void Collision(float DeltaTime) override;
	virtual void CollisionLateUpdate(float DeltaTime) override;
	virtual void Render(float DeltaTime) override;
	virtual Collider_Com* Clone() override = 0;

	COLLIDER_TYPE GetCollType() const { return m_CollType; }

protected:
	COLLIDER_TYPE m_CollType;

protected:
	Collider_Com();
	Collider_Com(const Collider_Com& CopyCollider);
	virtual ~Collider_Com() = 0;

public:
	friend class GameObject;
};

JEONG_END

