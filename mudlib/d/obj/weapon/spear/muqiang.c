// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

#include <weapon.h>

inherit SPEAR;

void create()
{
        set_name("ľǹ", ({"mu qiang", "qiang", "spear"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100);
                set("material", "wood");
                set("long", "����һľ�Ƶĳ�ǹ��������ʱ�õģ�\n");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������\n");
        }
        init_spear(15);
        setup();
}
