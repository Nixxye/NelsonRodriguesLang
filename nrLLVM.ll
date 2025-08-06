; ModuleID = 'NelsonRodriguesLang'
source_filename = "NelsonRodriguesLang"

@empty_str = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@init_str = private unnamed_addr constant [42 x i8] c"uma rua deserta banhada por uma luz fraca\00", align 1
@fmt = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@add_str = private unnamed_addr constant [23 x i8] c"No fim da rua um vulto\00", align 1
@fmt.1 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@alvo_str = private unnamed_addr constant [10 x i8] c"luz fraca\00", align 1
@subst_str = private unnamed_addr constant [21 x i8] c"escuridao que sufoca\00", align 1
@fmt.2 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1

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
  call void @pilha_set_topo(ptr %pilha_ptr, i32 3)
  br label %while_cond

while_cond:                                       ; preds = %while_body, %entrada
  %load_bool_tmp = load i1, ptr %"Esta chovendo4", align 1
  br i1 %load_bool_tmp, label %while_body, label %while_merge

while_body:                                       ; preds = %while_cond
  %tmpstr = load ptr, ptr %Lembranca, align 8
  %0 = call i32 (ptr, ...) @printf(ptr @fmt, ptr %tmpstr)
  %load_str = load ptr, ptr %Lembranca, align 8
  %str_concatenada_ptr = call ptr @string_concatenar(ptr %load_str, ptr @add_str)
  store ptr %str_concatenada_ptr, ptr %Lembranca, align 8
  %tmpstr5 = load ptr, ptr %Lembranca, align 8
  %1 = call i32 (ptr, ...) @printf(ptr @fmt.1, ptr %tmpstr5)
  %pilha_ptr6 = load ptr, ptr %Loira, align 8
  %peeked_val = call i32 @pilha_peek(ptr %pilha_ptr6)
  %tmp_sum = add i32 %peeked_val, 1
  call void @pilha_set_topo(ptr %pilha_ptr6, i32 %tmp_sum)
  %load_str7 = load ptr, ptr %Lembranca, align 8
  %str_substituida_ptr = call ptr @string_substituir(ptr %load_str7, ptr @alvo_str, ptr @subst_str)
  store ptr %str_substituida_ptr, ptr %Lembranca, align 8
  %tmpstr8 = load ptr, ptr %Lembranca, align 8
  %2 = call i32 (ptr, ...) @printf(ptr @fmt.2, ptr %tmpstr8)
  store i1 false, ptr %"Esta chovendo4", align 1
  br label %while_cond

while_merge:                                      ; preds = %while_cond
  ret i32 0
}

declare ptr @criar_pilha(i32)

declare void @pilha_push(ptr, i32)

declare ptr @string_criar(ptr)

declare void @pilha_set_topo(ptr, i32)

declare i32 @printf(ptr, ...)

declare ptr @string_concatenar(ptr, ptr)

declare i32 @pilha_peek(ptr)

declare ptr @string_substituir(ptr, ptr, ptr)
