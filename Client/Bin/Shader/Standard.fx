#include "Share.fx"

//fx������ ���ؽ��� �ȼ����̴� �ΰ� ���ÿ� ó���� �����ϴ�.

VS_OUTPUT_COLOR StandardColorVS(VS_INPUT_COLOR input)
{
    //0���� �ʱ�ȭ
    VS_OUTPUT_COLOR output = (VS_OUTPUT_COLOR)0;

    output.vPos = float4(input.vPos, 1.0f);
    output.vColor = input.vColor;

    return output;
}

//���ؽ� ���̴����� ���� OutPut�����Ͱ� �ȼ����̴� Input���� ���´�. (�Ž�Ŭ���� �������� �̹� �� ������ �س���(IA~) )
PS_OUTPUT_SINGLE StandardColorPS(VS_OUTPUT_COLOR input)
{
    PS_OUTPUT_SINGLE output = (PS_OUTPUT_SINGLE)0;

    output.vTarget0 = input.vColor;

    return output;
}


