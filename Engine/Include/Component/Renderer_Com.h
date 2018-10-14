#pragma once
#include "Component_Base.h"
JEONG_BEGIN

class Mesh;
class Shader;
class JEONG_DLL Renderer_Com : public Component_Base
{
public:
	bool Init() override;
	int Input(float DeltaTime) override;
	int Update(float DeltaTime) override;
	int LateUpdate(float DeltaTime) override;
	void Collision(float DeltaTime) override;
	void CollisionLateUpdate(float DeltaTime) override;
	void Render(float DeltaTime) override;
	Renderer_Com* Clone() override;

public:
	void SetMesh(Mesh* mesh);
	void SetMesh(const string& KeyName);
	void SetShader(Shader* shader);
	void SetShader(const string& KeyName);
	void SetLayOut(const string& KeyName);

private:
	void UpdateTransform();

private:
	Mesh* m_Mesh;
	Shader* m_Shader;
	ID3D11InputLayout* m_LayOut;
	float Temp;

private:
	Renderer_Com();
	Renderer_Com(const Renderer_Com& copyObject);
	~Renderer_Com();

public:
	friend class GameObject;
};

JEONG_END

