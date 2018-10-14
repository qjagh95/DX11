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
	size_t GetTextureCount() const { return m_vecImage.size(); }

	size_t GetWidth() const { return m_vecImage[0]->GetImage(0, 0, 0)->width; }
	size_t GetHeight()	const { return m_vecImage[0]->GetImage(0, 0, 0)->height; }
	const uint8_t* GetPixels() const { return m_vecImage[0]->GetPixels(); }
	size_t GetPixelSize() const { return m_vecImage[0]->GetPixelsSize(); }

private:
	bool CreateShaderResource();

private:
	///DirectXTex���� �����Ǵ� �̹����Լ�
	///�̹����� �������� �� �ֱ� �빮�� vector
	vector<ScratchImage*> m_vecImage;				
	///�̹����� �׳� �̹����� �ȼ������� ������ ���� ���̴�.
	///�� �ȼ������� �����ٰ� ���̴��� �Ѱܼ� �ű⼭ ������ �� ���������� ����Ѵ�.
	///�׷��⶧���� �Ʒ����� ������ �ʿ��ϴ�.
	ID3D11ShaderResourceView* m_ShaderResourceView;
	TCHAR m_FullPath[MAX_PATH];

private:	
	Texture();
	~Texture();

public:
	friend class ResourceManager;
};

JEONG_END

