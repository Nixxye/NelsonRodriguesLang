; ModuleID = 'NelsonRodriguesLang'
source_filename = "NelsonRodriguesLang"

@empty_str = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@strtmp = private unnamed_addr constant [19 x i8] c"luxuria e confusao\00", align 1
@prompt = private unnamed_addr constant [32 x i8] c"Digite o valor de Jose Dirceu: \00", align 1
@fmt = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@errmsg = private unnamed_addr constant [43 x i8] c"Erro: valor inv\C3\A1lido (esperado inteiro)\\n\00", align 1
@prompt.1 = private unnamed_addr constant [32 x i8] c"Digite o valor de Jose Dirceu: \00", align 1
@fmt.2 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@errmsg.3 = private unnamed_addr constant [43 x i8] c"Erro: valor inv\C3\A1lido (esperado inteiro)\\n\00", align 1
@fmt_str = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str = private unnamed_addr constant [12 x i8] c"Jose Dirceu\00", align 1

define i32 @main() {
entrada:
  %"Jose Dirceu" = alloca ptr, align 8
  %nova_pilha_ptr = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr, i32 0)
  store ptr %nova_pilha_ptr, ptr %"Jose Dirceu", align 8
  %Mariazinha = alloca ptr, align 8
  %nova_pilha_ptr1 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr1, i32 0)
  store ptr %nova_pilha_ptr1, ptr %Mariazinha, align 8
  %"o mundo dos n meros" = alloca ptr, align 8
  store ptr @empty_str, ptr %"o mundo dos n meros", align 8
  store ptr @strtmp, ptr %"o mundo dos n meros", align 8
  %0 = call i32 (ptr, ...) @printf(ptr @prompt)
  %temp_scanf = alloca i32, align 4
  %res_scanf = call i32 (ptr, ...) @scanf(ptr @fmt, ptr %temp_scanf)
  %scanf_failed = icmp ne i32 %res_scanf, 1
  br i1 %scanf_failed, label %erro, label %ok

ok:                                               ; preds = %erro, %entrada
  %valor_lido = load i32, ptr %temp_scanf, align 4
  %pilha_ptr = load ptr, ptr %"Jose Dirceu", align 8
  call void @pilha_set_topo(ptr %pilha_ptr, i32 %valor_lido)
  br label %while_cond

erro:                                             ; preds = %entrada
  %1 = call i32 (ptr, ...) @printf(ptr @errmsg)
  br label %ok

while_cond:                                       ; preds = %ok6, %ok
  %pilha_ptr_var = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val = call i32 @pilha_peek(ptr %pilha_ptr_var)
  %cmpgt = icmp sgt i32 %peeked_val, 0
  br i1 %cmpgt, label %while_body, label %while_merge

while_body:                                       ; preds = %while_cond
  %pilha_ptr2 = load ptr, ptr %"Jose Dirceu", align 8
  call void @pilha_push(ptr %pilha_ptr2, i32 0)
  %2 = call i32 (ptr, ...) @printf(ptr @prompt.1)
  %temp_scanf3 = alloca i32, align 4
  %res_scanf4 = call i32 (ptr, ...) @scanf(ptr @fmt.2, ptr %temp_scanf3)
  %scanf_failed5 = icmp ne i32 %res_scanf4, 1
  br i1 %scanf_failed5, label %erro7, label %ok6

while_merge:                                      ; preds = %while_cond
  %pilha_ptr10 = load ptr, ptr %"Jose Dirceu", align 8
  %popped_val = call i32 @pilha_pop(ptr %pilha_ptr10)
  br label %while_cond11

ok6:                                              ; preds = %erro7, %while_body
  %valor_lido8 = load i32, ptr %temp_scanf3, align 4
  %pilha_ptr9 = load ptr, ptr %"Jose Dirceu", align 8
  call void @pilha_set_topo(ptr %pilha_ptr9, i32 %valor_lido8)
  br label %while_cond

erro7:                                            ; preds = %while_body
  %3 = call i32 (ptr, ...) @printf(ptr @errmsg.3)
  br label %ok6

while_cond11:                                     ; preds = %while_body12, %while_merge
  %pilha_ptr_size = load ptr, ptr %"Jose Dirceu", align 8
  %tamanho_pilha = call i32 @pilha_obter_tamanho(ptr %pilha_ptr_size)
  %cmpgt14 = icmp sgt i32 %tamanho_pilha, 0
  br i1 %cmpgt14, label %while_body12, label %while_merge13

while_body12:                                     ; preds = %while_cond11
  %pilha_ptr15 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val16 = call i32 @pilha_peek(ptr %pilha_ptr15)
  %4 = call i32 (ptr, ...) @printf(ptr @fmt_str, ptr @var_name_str, i32 %peeked_val16)
  %pilha_ptr17 = load ptr, ptr %"Jose Dirceu", align 8
  %popped_val18 = call i32 @pilha_pop(ptr %pilha_ptr17)
  br label %while_cond11

while_merge13:                                    ; preds = %while_cond11
  ret i32 0
}

declare ptr @criar_pilha(i32)

declare void @pilha_push(ptr, i32)

declare i32 @printf(ptr, ...)

declare i32 @scanf(ptr, ...)

declare void @pilha_set_topo(ptr, i32)

declare i32 @pilha_peek(ptr)

declare i32 @pilha_pop(ptr)

declare i32 @pilha_obter_tamanho(ptr)
