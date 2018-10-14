#include "Camera_Com.h"
#include "../GameObject.h"
#include "Transform_Com.h"
JEONG_USING

Camera_Com::Camera_Com()
{
	m_ComType = CT_CAMERA;
	m_CameraType = CT_PERSPECTIVE;
}

Camera_Com::~Camera_Com()
{
}

Camera_Com::Camera_Com(const Camera_Com & camera)
	:Component_Base(camera)
{
	m_CameraType = camera.m_CameraType;
	m_View = camera.m_View;
	m_Projection = camera.m_Projection;
}

bool Camera_Com::Init()
{
	return true;
}

int Camera_Com::Input(float DeltaTime)
{
	return 0;
}

int Camera_Com::Update(float DeltaTime)
{
	m_View.Identity();

	//memcpy 41 ~ 43��ġ == Pos��ġ��.
	memcpy(&m_View[3][0], &m_Transform->GetWorldPos(), sizeof(Vector3));

	return 0;
}

int Camera_Com::LateUpdate(float DeltaTime)
{
	return 0;
}

void Camera_Com::Collision(float DeltaTime)
{
}

void Camera_Com::CollisionLateUpdate(float DeltaTime)
{
}

void Camera_Com::Render(float DeltaTime)
{
}

Camera_Com * Camera_Com::Clone()
{
	return new Camera_Com(*this);
}

void Camera_Com::SetCameraType(CAMERA_TYPE eType)
{
	m_CameraType = eType;

	switch (eType)
	{
		case CT_PERSPECTIVE:
			m_Projection = XMMatrixPerspectiveFovLH(DegreeToRadian(m_ViewAngle), m_Width / m_Height, m_Near, m_Far);
			break;

		case CT_ORTHO:
			/*
			(���ؽ� ������)     (�������)
			0, 0.5, 0, 1		100 0   0 0
			0.5, -0.5, 0, 1		0   100 0 0
			-0.5, -0.5, 0, 1	0   0   1 0

			//������ ���� ���� ��������� �����������Ŀ� ��ȯ����.
			100 100 0 1	100,	1/400 0      0 0
			150, 0, 1			0     1/-300 0 0
			150, 50, 0, 1		0     0      1 0
			50, 50, 0, 1		-1    1      1 1

			//���� ��
			-0.75, 0.5
			-0.625, 0.83

			//�������� ����
			2/(right-left)      0					0            0
			0					2/(top-bottom)      0            0
			0					0					1/(zf-zn)	 0
			(left+right)/(left-right)  (top+bottom)/(bottom-top)  zn/(zn-zf)  
			*/

			//���⼭ Pos�� �������� ����� ���´�. (�»�ܱ���)
			m_Projection = XMMatrixOrthographicOffCenterLH(0.0f, m_Width, 0.0f, m_Height, m_Near, m_Far);
			break;
			//���������� �� ������ ���Ͽ� �������ڴٴ� ��.
	}
}

void Camera_Com::SetCameraInfo(CAMERA_TYPE eType, float Width, float Height, float ViewAngle, float Near, float Far)
{
	m_Width = Width;
	m_Height= Height;
	m_Near = Near;
	m_Far = Far;
	m_ViewAngle = ViewAngle;
	
	SetCameraType(eType);
}

void Camera_Com::SetWidth(float Width)
{
	m_Width = Width;
	SetCameraType(m_CameraType);
}

void Camera_Com::SetHeight(float Height)
{
	m_Height = Height;
	SetCameraType(m_CameraType);
}

void Camera_Com::SetViewAngle(float Angle)
{
	m_ViewAngle = Angle;
	SetCameraType(m_CameraType);
}

void Camera_Com::SetNear(float Near)
{
	m_Near = Near;
	SetCameraType(m_CameraType);
}

void Camera_Com::SetFar(float Far)
{
	m_Far = Far;
	SetCameraType(m_CameraType);
}

Matrix Camera_Com::GetViewMatrix() const
{
	return m_View;
}

Matrix Camera_Com::GetProjection() const
{
	return m_Projection;
}