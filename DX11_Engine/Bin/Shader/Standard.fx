#include "Share.fx"
//fx������ ���ؽ��� �ȼ����̴� �ΰ� ���ÿ� ó���� �����ϴ�.

//////////////////////////////////ColorShader//////////////////////////

VS_OUTPUT_COLOR Standard_Color_VS(VS_INPUT_COLOR input)
{
    //0���� �ʱ�ȭ
    VS_OUTPUT_COLOR output = (VS_OUTPUT_COLOR)0;
    //mul = ���ϱ� (������İ�)
    output.vPos = mul(float4(input.vPos, 1.0f), g_WVP);
    output.vColor = input.vColor;

    return output;
}

//���ؽ� ���̴����� ���� OutPut�����Ͱ� �ȼ����̴� Input���� ���´�. (�Ž�Ŭ���� �������� �̹� �� ������ �س���(IA~) )
PS_OUTPUT_SINGLE Standard_Color_PS(VS_OUTPUT_COLOR input)
{
    PS_OUTPUT_SINGLE output = (PS_OUTPUT_SINGLE)0;

    output.vTarget0 = input.vColor;

    return output;
}

//////////////////////////////////ColorShader//////////////////////////


//////////////////////////////////UVShader/////////////////////////////

VS_OUTPUT_UV Standard_UV_VS(VS_INPUT_UV input)
{
    VS_OUTPUT_UV output = (VS_OUTPUT_UV)0;

    //API�� �ߴ� �߽������� (newPos = Pos - Size * Pivot)�̰Ŷ� �Ȱ���.
    //���ؽ��� ����������ȯ �� ��ǥ�� 0.n���¿��� �߽����� ��´�.
    float3 TempPos = input.vPos - (g_Pivot * g_Length);

    output.vPos = mul(float4(TempPos, 1.0f), g_WVP);
    output.vUV = input.vUV;

    return output;
}

PS_OUTPUT_SINGLE Standard_UV_PS(VS_OUTPUT_UV input)
{
    PS_OUTPUT_SINGLE output = (PS_OUTPUT_SINGLE)0;
    
    //Diffuse(Texture2D)�� SampleState(���������� UV)�� �־��ְ� ���� ���������� ���Ѵ�
    output.vTarget0 = Diffuse.Sample(DiffuseSampler, input.vUV) * g_MaterialDiffuse;
    return output;
}

//////////////////////////////////UVShader/////////////////////////////