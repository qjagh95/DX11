#pragma once
#include "../RefCount.h"
#include "DirectXTex.h"

JEONG_BEGIN

class JEONG_DLL Texture : public RefCount
{
public:
	bool LoadTexture(const string& TextureName, const TCHAR* FileName, const string& PathKey = TEXTURE_PATH);
	bool LoadTextureFromFullPath(const string& TextureName, const TCHAR* FullPath);
	void SetShaderResource(int RegisterNumber);

private:
	bool CreateShaderResource();

private:
	///DirectXTex에서 제공되는 이미지함수
	///이미지가 여러장일 수 있기 대문에 vector
	vector<ScratchImage*> m_vecImage;				
	///이미지는 그냥 이미지의 픽셀정보를 가지고 있을 뿐이다.
	///그 픽셀정보를 가져다가 쉐이더로 넘겨서 거기서 정보를 뜯어서 색상정보를 써야한다.
	///그렇기때문에 아랫놈이 무조건 필요하다.
	ID3D11ShaderResourceView* m_ShaderResourceView;
	TCHAR m_FullPath[MAX_PATH];

private:	
	Texture();
	~Texture();

public:
	friend class ResourceManager;
};

JEONG_END

