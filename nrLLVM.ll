; ModuleID = 'NelsonRodriguesLang'
source_filename = "NelsonRodriguesLang"

@empty_str = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@init_str = private unnamed_addr constant [42 x i8] c"uma rua deserta banhada por uma luz fraca\00", align 1
@fmt = private unnamed_addr constant [19 x i8] c"Cenario atual: %s\0A\00", align 1
@add_str = private unnamed_addr constant [23 x i8] c"No fim da rua um vulto\00", align 1
@fmt.1 = private unnamed_addr constant [19 x i8] c"Cenario atual: %s\0A\00", align 1
@alvo_str = private unnamed_addr constant [10 x i8] c"luz fraca\00", align 1
@subst_str = private unnamed_addr constant [21 x i8] c"escuridao que sufoca\00", align 1
@fmt.2 = private unnamed_addr constant [19 x i8] c"Cenario atual: %s\0A\00", align 1
@add_str.3 = private unnamed_addr constant [29 x i8] c"o cheiro de chuva e tragedia\00", align 1
@fmt.4 = private unnamed_addr constant [19 x i8] c"Cenario atual: %s\0A\00", align 1
@alvo_str.5 = private unnamed_addr constant [6 x i8] c"vulto\00", align 1
@subst_str.6 = private unnamed_addr constant [22 x i8] c"homem de terno branco\00", align 1
@fmt.7 = private unnamed_addr constant [19 x i8] c"Cenario atual: %s\0A\00", align 1

define i32 @main() {
entrada:
  %Alaide = alloca ptr, align 8
  %nova_pilha_ptr = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr, i32 0)
  store ptr %nova_pilha_ptr, ptr %Alaide, align 8
  %Loira = alloca ptr, align 8
  %nova_pilha_ptr1 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr1, i32 0)
  store ptr %nova_pilha_ptr1, ptr %Loira, align 8
  %Joao = alloca ptr, align 8
  %nova_pilha_ptr2 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr2, i32 0)
  store ptr %nova_pilha_ptr2, ptr %Joao, align 8
  %Abismo = alloca ptr, align 8
  %nova_pilha_ptr3 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr3, i32 0)
  store ptr %nova_pilha_ptr3, ptr %Abismo, align 8
  %"Esta chovendo" = alloca i1, align 1
  store i1 false, ptr %"Esta chovendo", align 1
  %"Esta chovendo4" = alloca i1, align 1
  store i1 true, ptr %"Esta chovendo4", align 1
  %Lembranca = alloca ptr, align 8
  store ptr @empty_str, ptr %Lembranca, align 8
  %nova_str_ptr = call ptr @string_criar(ptr @init_str)
  store ptr %nova_str_ptr, ptr %Lembranca, align 8
  %pilha_ptr = load ptr, ptr %Abismo, align 8
  call void @pilha_set_topo(ptr %pilha_ptr, i32 5)
  br label %while_cond

while_cond:                                       ; preds = %if_merge36, %entrada
  %load_bool_tmp = load i1, ptr %"Esta chovendo4", align 1
  br i1 %load_bool_tmp, label %while_body, label %while_merge

while_body:                                       ; preds = %while_cond
  %tmpstr = load ptr, ptr %Lembranca, align 8
  %0 = call i32 (ptr, ...) @printf(ptr @fmt, ptr %tmpstr)
  %pilha_ptr5 = load ptr, ptr %Loira, align 8
  %peeked_val = call i32 @pilha_peek(ptr %pilha_ptr5)
  %tmp_sum = add i32 %peeked_val, 1
  call void @pilha_set_topo(ptr %pilha_ptr5, i32 %tmp_sum)
  %pilha_ptr_var = load ptr, ptr %Loira, align 8
  %peeked_val6 = call i32 @pilha_peek(ptr %pilha_ptr_var)
  %cmpeq = icmp eq i32 %peeked_val6, 1
  br i1 %cmpeq, label %if_then, label %if_merge

while_merge:                                      ; preds = %while_cond
  ret i32 0

if_then:                                          ; preds = %while_body
  %load_str = load ptr, ptr %Lembranca, align 8
  %str_concatenada_ptr = call ptr @string_concatenar(ptr %load_str, ptr @add_str)
  store ptr %str_concatenada_ptr, ptr %Lembranca, align 8
  %tmpstr7 = load ptr, ptr %Lembranca, align 8
  %1 = call i32 (ptr, ...) @printf(ptr @fmt.1, ptr %tmpstr7)
  br label %if_merge

if_merge:                                         ; preds = %if_then, %while_body
  %pilha_ptr_var8 = load ptr, ptr %Loira, align 8
  %peeked_val9 = call i32 @pilha_peek(ptr %pilha_ptr_var8)
  %cmpeq10 = icmp eq i32 %peeked_val9, 3
  br i1 %cmpeq10, label %if_then11, label %if_merge12

if_then11:                                        ; preds = %if_merge
  %load_str13 = load ptr, ptr %Lembranca, align 8
  %str_substituida_ptr = call ptr @string_substituir(ptr %load_str13, ptr @alvo_str, ptr @subst_str)
  store ptr %str_substituida_ptr, ptr %Lembranca, align 8
  %tmpstr14 = load ptr, ptr %Lembranca, align 8
  %2 = call i32 (ptr, ...) @printf(ptr @fmt.2, ptr %tmpstr14)
  br label %if_merge12

if_merge12:                                       ; preds = %if_then11, %if_merge
  %pilha_ptr_var15 = load ptr, ptr %Loira, align 8
  %peeked_val16 = call i32 @pilha_peek(ptr %pilha_ptr_var15)
  %cmpeq17 = icmp eq i32 %peeked_val16, 1
  br i1 %cmpeq17, label %if_then18, label %if_merge19

if_then18:                                        ; preds = %if_merge12
  %load_str20 = load ptr, ptr %Lembranca, align 8
  %str_concatenada_ptr21 = call ptr @string_concatenar(ptr %load_str20, ptr @add_str.3)
  store ptr %str_concatenada_ptr21, ptr %Lembranca, align 8
  %tmpstr22 = load ptr, ptr %Lembranca, align 8
  %3 = call i32 (ptr, ...) @printf(ptr @fmt.4, ptr %tmpstr22)
  br label %if_merge19

if_merge19:                                       ; preds = %if_then18, %if_merge12
  %pilha_ptr_var23 = load ptr, ptr %Loira, align 8
  %peeked_val24 = call i32 @pilha_peek(ptr %pilha_ptr_var23)
  %cmpeq25 = icmp eq i32 %peeked_val24, 4
  br i1 %cmpeq25, label %if_then26, label %if_merge27

if_then26:                                        ; preds = %if_merge19
  %load_str28 = load ptr, ptr %Lembranca, align 8
  %str_substituida_ptr29 = call ptr @string_substituir(ptr %load_str28, ptr @alvo_str.5, ptr @subst_str.6)
  store ptr %str_substituida_ptr29, ptr %Lembranca, align 8
  %tmpstr30 = load ptr, ptr %Lembranca, align 8
  %4 = call i32 (ptr, ...) @printf(ptr @fmt.7, ptr %tmpstr30)
  br label %if_merge27

if_merge27:                                       ; preds = %if_then26, %if_merge19
  %pilha_ptr_var31 = load ptr, ptr %Loira, align 8
  %peeked_val32 = call i32 @pilha_peek(ptr %pilha_ptr_var31)
  %pilha_ptr_var33 = load ptr, ptr %Abismo, align 8
  %peeked_val34 = call i32 @pilha_peek(ptr %pilha_ptr_var33)
  %cmpgt = icmp sgt i32 %peeked_val32, %peeked_val34
  br i1 %cmpgt, label %if_then35, label %if_merge36

if_then35:                                        ; preds = %if_merge27
  store i1 false, ptr %"Esta chovendo4", align 1
  br label %if_merge36

if_merge36:                                       ; preds = %if_then35, %if_merge27
  br label %while_cond
}

declare ptr @criar_pilha(i32)

declare void @pilha_push(ptr, i32)

declare ptr @string_criar(ptr)

declare void @pilha_set_topo(ptr, i32)

declare i32 @printf(ptr, ...)

declare i32 @pilha_peek(ptr)

declare ptr @string_concatenar(ptr, ptr)

declare ptr @string_substituir(ptr, ptr, ptr)
