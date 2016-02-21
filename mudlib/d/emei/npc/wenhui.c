// wenhui.c ����Сʦ̫

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("����Сʦ̫", ({ "wenhui","wenhui xiaoshitai","xiaoshitai"}));
        set("long",
                "���Ƕ����ɵĵ�������ӡ�\n");
        set("gender", "Ů��");
        set("age", 15);
        set("attitude", "peaceful");
        set("mingwang", 100);
        set("class", "bonze");

        set("str", 20);
        set("int", 20);
        set("con", 22);
        set("per", 30);

        set("max_kee", 150);
        set("max_gin", 100);
        set("force", 150);
        set("max_force", 150);

        set("combat_exp", 2000);
        set("score", 1000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 5);
        set("chat_chance",5);
        set("chat_msg",({
      "���͵�:ÿ�������Ҫ������,����һ�챻�ҿ���.\n",
      "���͵�:��ʦ���ں󶴵��ٲ��϶�����,�Ӳ�����.\n",
      "���͵�:��˵�����ͨ����һ��,�����ϲ�����ȥ����.\n",
      }));

        create_family("������", 5, "����");

        setup();
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/armor/ni-cloth.c")->wear();
        carry_object("/obj/armor/ni-xie")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
               remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
     if( !ob || environment(ob) != environment() ) return;
     command( "say ��,ˮ������?�ٶ����ѽ��\n");
}

