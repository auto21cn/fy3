// ling-huchong.c

inherit NPC;

void create()
{
        set_name("�����", ({ "ling huchong", "ling", "huchong" }) );

        set("gender", "����");
        set("age", 29);
        set("long",
                "������ǻ�ɽ�ɵĿ��Ŵ���ӣ�Ҳ�Ƿ�������¾Ž��ڳ����е�Ψһ���ˡ�\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 30);

        set("max_kee",2500);
        set("max_gin",1000);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 100);

        set("combat_exp", 1000000);
        set("shen_type", 1);
        set("score", 200000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 80);
        set_skill("sword", 150);
        set_skill("force", 100);
        set_skill("parry", 150);
        set_skill("dodge", 100);
        set_skill("literate", 50);

        set_skill("huashan-jianfa", 150);
        set_skill("dugu-jiujian", 150);
        set_skill("zixia-shengong", 100);
        set_skill("huashan-quanfa", 80);
        set_skill("feiyan-huixiang", 100);

        map_skill("sword", "dugu-jiujian");
        map_skill("parry", "dugu-jiujian");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-quanfa");
        map_skill("dodge", "feiyan-huixiang");

        create_family("��ɽ��", 14, "����");

        setup();

        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/cloth")->wear();

}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",2 , ob);
        }
}
void greeting(object ob)
{
}
