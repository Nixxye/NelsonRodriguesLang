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
  %pilha_ptr2 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val3 = call i32 @pilha_peek(ptr %pilha_ptr2)
  %tmp_sum4 = add i32 %peeked_val3, -1
  call void @pilha_set_topo(ptr %pilha_ptr2, i32 %tmp_sum4)
  %pilha_ptr5 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val6 = call i32 @pilha_peek(ptr %pilha_ptr5)
  %0 = call i32 (ptr, ...) @printf(ptr @fmt_str, ptr @var_name_str, i32 %peeked_val6)
  %pilha_ptr7 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val8 = call i32 @pilha_peek(ptr %pilha_ptr7)
  %1 = call i32 (ptr, ...) @printf(ptr @fmt_str.3, ptr @var_name_str.4, i32 %peeked_val8)
  %pilha_ptr_var = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val9 = call i32 @pilha_peek(ptr %pilha_ptr_var)
  %pilha_ptr_var10 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val11 = call i32 @pilha_peek(ptr %pilha_ptr_var10)
  %cmpgt = icmp sgt i32 %peeked_val9, %peeked_val11
  %pilha_ptr12 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val13 = call i32 @pilha_peek(ptr %pilha_ptr12)
  %tmp_sum14 = add i32 %peeked_val13, -1
  call void @pilha_set_topo(ptr %pilha_ptr12, i32 %tmp_sum14)
  %pilha_ptr15 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val16 = call i32 @pilha_peek(ptr %pilha_ptr15)
  %tmp_sum17 = add i32 %peeked_val16, 1
  call void @pilha_set_topo(ptr %pilha_ptr15, i32 %tmp_sum17)
  br i1 %cmpgt, label %if_then_bloco, label %if_merge_bloco

if_then_bloco:                                    ; preds = %entrada
  br label %if_merge_bloco

if_merge_bloco:                                   ; preds = %if_then_bloco, %entrada
  %pilha_ptr18 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val19 = call i32 @pilha_peek(ptr %pilha_ptr18)
  %2 = call i32 (ptr, ...) @printf(ptr @fmt_str.5, ptr @var_name_str.6, i32 %peeked_val19)
  %pilha_ptr20 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val21 = call i32 @pilha_peek(ptr %pilha_ptr20)
  %3 = call i32 (ptr, ...) @printf(ptr @fmt_str.7, ptr @var_name_str.8, i32 %peeked_val21)
  ret i32 0
}

declare ptr @criar_pilha(i32)

declare void @pilha_push(ptr, i32)

declare i32 @pilha_peek(ptr)

declare void @pilha_set_topo(ptr, i32)

declare i32 @printf(ptr, ...)
