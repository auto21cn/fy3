// heal.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("ս�����˹����ˣ�������\n");

        if ((int)me->query_skill("jiuyin-shengong", 1) < 20)
                return notify_fail("��ľ�������Ϊ��������\n");
        if( (int)me->query("force") < 50 ) // - (int)me->query("max_force") < 50 )
                return notify_fail("�������������\n");
       
       if( (int)me->query("eff_kee") == (int)me->query("max_kee") )
              return notify_fail("������û�����κ��ˡ�\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

        write( HIW "��ȫ�����ɣ����������,�������澭�ķ���Ϊ�Լ����ˡ�\n" NOR);
        message("vision",
                BLU + me->name() + "��������ʼ�������������,��Ȼ�³�һ����Ѫ����ɫ�������ö��ˡ�\n" NOR,
                environment(me), me);

        me->receive_curing("kee", 10 + (int)me->query_skill("force")/5 );
        me->add("force", -50);

        return 1;
}