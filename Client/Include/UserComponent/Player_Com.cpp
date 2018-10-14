#include "Player_Com.h"
#include "GameObject.h"

#include "KeyInput.h"

#include "Component/Transform_Com.h"
#include "Component/Renderer_Com.h"
#include "Component/Material_Com.h"

#include "../UserComponent/Bullet_Com.h"
#include "../UserComponent/BulletRot_Com.h"

Player_Com::Player_Com()
	:isCharge(false),isAlive(false), ScaleVar(0.0f)
{
}

Player_Com::Player_Com(const Player_Com & userCom)
	:UserComponent_Base(userCom)
{
}

Player_Com::~Player_Com()
{
}

bool Player_Com::Init()
{
	KeyInput::Get().CreateKey("MoveLeft", VK_LEFT);
	KeyInput::Get().CreateKey("MoveRight", VK_RIGHT);
	KeyInput::Get().CreateKey("MoveUp", VK_UP);
	KeyInput::Get().CreateKey("MoveDown", VK_DOWN);

	KeyInput::Get().CreateKey("S1", VK_F1);
	KeyInput::Get().CreateKey("S2", VK_F2);
	KeyInput::Get().CreateKey("S3", VK_F3);
	KeyInput::Get().CreateKey("S4", VK_F4);


	Renderer_Com* RenderComponent = m_Object->AddComponent<Renderer_Com>("PlayerRender");
	RenderComponent->SetMesh("TextureRect");
	RenderComponent->SetRenderState(ALPHA_BLEND);
	SAFE_RELEASE(RenderComponent);

	Material_Com* MaterialComponent = m_Object->FindComponentFromType<Material_Com>(CT_MATERIAL);
	MaterialComponent->SetMaterial(Vector4::Yellow);
	MaterialComponent->SetDiffuseTexture(0, "Player", TEXT("Player.png"));
	SAFE_RELEASE(MaterialComponent);

	m_Transform->SetWorldScale(100.0f, 100.0f, 1.0f);
	m_Transform->SetWorldPivot(0.5f, 0.0f, 0.0f);
	m_Transform->SetWorldPos(600.0f, 0.0f, 1.0f);

	return true;
}

int Player_Com::Input(float DeltaTime)
{
	Material_Com* getMaterial = m_Object->FindComponentFromType<Material_Com>(CT_MATERIAL);
	getMaterial->SetMaterial(Vector4::White);

	//나는 정면에서 보고있고 그리는건 앞 에서 그리기때문에 각도-
	//if (KeyInput::Get().KeyPress("MoveLeft"))
	//	m_Transform->RotationZ(180.0f, DeltaTime);
	//else if (KeyInput::Get().KeyPress("MoveRight"))
	//	m_Transform->RotationZ(-180.0f, DeltaTime);

	if (KeyInput::Get().KeyPress("MoveUp"))
		m_Transform->Move(AXIS_Y, 200.0f, DeltaTime);
	else if (KeyInput::Get().KeyPress("MoveDown"))
		m_Transform->Move(AXIS_Y, -200.0f, DeltaTime);
	if (KeyInput::Get().KeyPress("MoveRight"))
		m_Transform->Move(AXIS_X, 200.0f, DeltaTime);
	else if (KeyInput::Get().KeyPress("MoveLeft"))
		m_Transform->Move(AXIS_X, -200.0f, DeltaTime);

	if (KeyInput::Get().KeyDown("S1"))
	{
		GameObject* newClone1 = GameObject::CreateClone("BulletObject", "Bullet_Clone", m_Layer);
		newClone1->GetTransform()->SetWorldPos(m_Transform->GetWorldPos());
		newClone1->GetTransform()->RotationZ(45.0f);
		newClone1->SetMoveDir(MD_UP);
		SAFE_RELEASE(newClone1);

		GameObject* newClone2 = GameObject::CreateClone("BulletObject", "Bullet_Clone", m_Layer);
		newClone2->GetTransform()->SetWorldPos(m_Transform->GetWorldPos());
		newClone2->GetTransform()->RotationZ(0.0f);
		newClone2->SetMoveDir(MD_UP);
		SAFE_RELEASE(newClone2);

		GameObject* newClone3 = GameObject::CreateClone("BulletObject", "Bullet_Clone", m_Layer);
		newClone3->GetTransform()->SetWorldPos(m_Transform->GetWorldPos());
		newClone3->GetTransform()->RotationZ(-45.0f);
		newClone3->SetMoveDir(MD_UP);
		SAFE_RELEASE(newClone3);

		getMaterial->SetMaterial(Vector4::DarkCyan);
	}

	if (KeyInput::Get().KeyDown("S2"))
	{
		BaseBullet = GameObject::CreateClone("BulletObject", "Bullet_Clone", m_Layer);
		BaseBullet->GetTransform()->SetWorldPos(m_Transform->GetWorldPos());
	}

	if (KeyInput::Get().KeyPress("S2"))
	{
		ScaleVar += 500.0f * DeltaTime;

		Bullet_Com* getCom = BaseBullet->FindComponentFromType<Bullet_Com>((COMPONENT_TYPE)UT_BULLET);
		getCom->GetTransform()->SetWorldScale(ScaleVar, ScaleVar, 0.0f);
		getCom->SetMoveSpeed(0.0f);

		SAFE_RELEASE(getCom);
	}

	if (KeyInput::Get().KeyUp("S2"))
	{
		Bullet_Com* getCom = BaseBullet->FindComponentFromType<Bullet_Com>((COMPONENT_TYPE)UT_BULLET);
		getCom->SetMoveSpeed(500.0f);
		ScaleVar = 0.0f;

		SAFE_RELEASE(getCom);
		SAFE_RELEASE(BaseBullet);
	}

	if (KeyInput::Get().KeyDown("S3"))
	{
		GameObject* newClone3 = GameObject::CreateClone("BulletObjectRot", "BulletRot_Clone", m_Layer);
		newClone3->GetTransform()->SetWorldPos(m_Transform->GetWorldPos());   
		newClone3->SetMoveDir(MD_UP);

		BulletRot_Com* getCom = newClone3->FindComponentFromTag<BulletRot_Com>("BulletRot_Com");
		GameObject* TargetObject = GameObject::FindObject("Monster");
		getCom->SetTarget(TargetObject);

		SAFE_RELEASE(newClone3);
		SAFE_RELEASE(TargetObject);
		SAFE_RELEASE(getCom);
	}

	if (KeyInput::Get().KeyDown("S4"))
	{
		GameObject* newClone1 = GameObject::CreateClone("BulletObjectRot", "BulletRot_Clone", m_Layer);
		newClone1->GetTransform()->SetWorldPos(m_Transform->GetWorldPos());
		newClone1->SetMoveDir(MD_UP);
		newClone1->GetTransform()->SetWorldRotZ(135.0f);

		BulletRot_Com* getCom1 = newClone1->FindComponentFromTag<BulletRot_Com>("BulletRot_Com");
		GameObject* TargetObject = GameObject::FindObject("Monster");
		getCom1->SetTarget(TargetObject);

		GameObject* newClone2 = GameObject::CreateClone("BulletObjectRot", "BulletRot_Clone", m_Layer);
		newClone2->GetTransform()->SetWorldPos(m_Transform->GetWorldPos());
		newClone2->SetMoveDir(MD_UP);
		newClone2->GetTransform()->SetWorldRotZ(-135.0f);

		BulletRot_Com* getCom2 = newClone2->FindComponentFromTag<BulletRot_Com>("BulletRot_Com");
		getCom2->SetTarget(TargetObject);

		SAFE_RELEASE(newClone1);
		SAFE_RELEASE(newClone2);
		SAFE_RELEASE(TargetObject);
		SAFE_RELEASE(getCom1);
		SAFE_RELEASE(getCom2);
	}

	SAFE_RELEASE(getMaterial);

	return 0;
}

int Player_Com::Update(float DeltaTime)
{
	return 0;
}

int Player_Com::LateUpdate(float DeltaTime)
{
	return 0;
}

void Player_Com::Collision(float DeltaTime)
{
}

void Player_Com::CollisionLateUpdate(float DeltaTime)
{
}

void Player_Com::Render(float DeltaTime)
{
}

Player_Com * Player_Com::Clone()
{
	return new Player_Com(*this);
}
