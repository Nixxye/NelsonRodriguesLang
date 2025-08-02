; ModuleID = 'NelsonRodriguesLang'
source_filename = "NelsonRodriguesLang"

@empty_str = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@strtmp = private unnamed_addr constant [19 x i8] c"luxuria e confusao\00", align 1
@empty_str.1 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@strtmp.2 = private unnamed_addr constant [31 x i8] c"nao sei o que nao sei o que la\00", align 1
@fmt_str = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str = private unnamed_addr constant [14 x i8] c"Maria Roberta\00", align 1
@fmt_str.3 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.4 = private unnamed_addr constant [12 x i8] c"Jose Dirceu\00", align 1
@fmt_str.5 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.6 = private unnamed_addr constant [14 x i8] c"Maria Roberta\00", align 1
@fmt_str.7 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.8 = private unnamed_addr constant [12 x i8] c"Jose Dirceu\00", align 1

define i32 @main() {
entrada:
  %"Jose Dirceu" = alloca ptr, align 8
  %nova_pilha_ptr = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr, i32 0)
  store ptr %nova_pilha_ptr, ptr %"Jose Dirceu", align 8
  %"Maria Roberta" = alloca ptr, align 8
  %nova_pilha_ptr1 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr1, i32 0)
  store ptr %nova_pilha_ptr1, ptr %"Maria Roberta", align 8
  %"Avenida Copacabana" = alloca ptr, align 8
  store ptr @empty_str, ptr %"Avenida Copacabana", align 8
  store ptr @strtmp, ptr %"Avenida Copacabana", align 8
  %"Cenario 2" = alloca ptr, align 8
  store ptr @empty_str.1, ptr %"Cenario 2", align 8
  store ptr @strtmp.2, ptr %"Cenario 2", align 8
  %pilha_ptr = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val = call i32 @pilha_peek(ptr %pilha_ptr)
  %tmp_sum = add i32 %peeked_val, 1
  call void @pilha_set_topo(ptr %pilha_ptr, i32 %tmp_sum)
  %pilha_ptr2 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val3 = call i32 @pilha_peek(ptr %pilha_ptr2)
  %0 = call i32 (ptr, ...) @printf(ptr @fmt_str, ptr @var_name_str, i32 %peeked_val3)
  %pilha_ptr4 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val5 = call i32 @pilha_peek(ptr %pilha_ptr4)
  %tmp_sum6 = add i32 %peeked_val5, -1
  call void @pilha_set_topo(ptr %pilha_ptr4, i32 %tmp_sum6)
  %pilha_ptr7 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val8 = call i32 @pilha_peek(ptr %pilha_ptr7)
  %1 = call i32 (ptr, ...) @printf(ptr @fmt_str.3, ptr @var_name_str.4, i32 %peeked_val8)
  %pilha_ptr9 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val10 = call i32 @pilha_peek(ptr %pilha_ptr9)
  %2 = call i32 (ptr, ...) @printf(ptr @fmt_str.5, ptr @var_name_str.6, i32 %peeked_val10)
  %load_voce = load i32, ptr %"Jose Dirceu", align 4
  %load_eu = load i32, ptr %"Maria Roberta", align 4
  %cmpgt = icmp sgt i32 %load_voce, %load_eu
  %load_eu11 = load i32, ptr %"Maria Roberta", align 4
  br i1 %cmpgt, label %if_then, label %if_merge

if_then:                                          ; preds = %entrada
  %pilha_ptr12 = load ptr, ptr %"Jose Dirceu", align 8
  call void @pilha_set_topo(ptr %pilha_ptr12, i32 %load_eu11)
  br label %if_merge

if_merge:                                         ; preds = %if_then, %entrada
  %pilha_ptr13 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val14 = call i32 @pilha_peek(ptr %pilha_ptr13)
  %3 = call i32 (ptr, ...) @printf(ptr @fmt_str.7, ptr @var_name_str.8, i32 %peeked_val14)
  ret i32 0
}

declare ptr @criar_pilha(i32)

declare void @pilha_push(ptr, i32)

declare i32 @pilha_peek(ptr)

declare void @pilha_set_topo(ptr, i32)

declare i32 @printf(ptr, ...)
