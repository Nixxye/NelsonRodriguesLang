; ModuleID = 'NelsonRodriguesLang'
source_filename = "NelsonRodriguesLang"

@empty_str = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@strtmp = private unnamed_addr constant [19 x i8] c"luxuria e confusao\00", align 1
@fmt_str = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str = private unnamed_addr constant [10 x i8] c"Joaozinho\00", align 1
@fmt_str.1 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.2 = private unnamed_addr constant [10 x i8] c"Joaozinho\00", align 1

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
  %Joaozinho = alloca ptr, align 8
  %nova_pilha_ptr2 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr2, i32 0)
  store ptr %nova_pilha_ptr2, ptr %Joaozinho, align 8
  %Robertinha = alloca ptr, align 8
  %nova_pilha_ptr3 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr3, i32 0)
  store ptr %nova_pilha_ptr3, ptr %Robertinha, align 8
  %"Avenida Copacabana" = alloca ptr, align 8
  store ptr @empty_str, ptr %"Avenida Copacabana", align 8
  store ptr @strtmp, ptr %"Avenida Copacabana", align 8
  %"Esta chovendo" = alloca i1, align 1
  store i1 false, ptr %"Esta chovendo", align 1
  store i1 true, ptr %"Esta chovendo", align 1
  %pilha_ptr_var = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val = call i32 @pilha_peek(ptr %pilha_ptr_var)
  %addtmp = add i32 %peeked_val, 3
  %pilha_ptr = load ptr, ptr %Joaozinho, align 8
  call void @pilha_set_topo(ptr %pilha_ptr, i32 %addtmp)
  br label %do_body

do_body:                                          ; preds = %do_cond, %entrada
  %pilha_ptr4 = load ptr, ptr %Joaozinho, align 8
  %peeked_val5 = call i32 @pilha_peek(ptr %pilha_ptr4)
  %tmp_sum = add i32 %peeked_val5, -1
  call void @pilha_set_topo(ptr %pilha_ptr4, i32 %tmp_sum)
  %pilha_ptr6 = load ptr, ptr %Joaozinho, align 8
  %peeked_val7 = call i32 @pilha_peek(ptr %pilha_ptr6)
  %0 = call i32 (ptr, ...) @printf(ptr @fmt_str, ptr @var_name_str, i32 %peeked_val7)
  %pilha_ptr_var8 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val9 = call i32 @pilha_peek(ptr %pilha_ptr_var8)
  %pilha_ptr_var10 = load ptr, ptr %Joaozinho, align 8
  %peeked_val11 = call i32 @pilha_peek(ptr %pilha_ptr_var10)
  %cmplt = icmp slt i32 %peeked_val9, %peeked_val11
  br label %do_cond

do_cond:                                          ; preds = %do_body
  br i1 %cmplt, label %do_body, label %do_merge

do_merge:                                         ; preds = %do_cond
  %pilha_ptr12 = load ptr, ptr %Joaozinho, align 8
  %peeked_val13 = call i32 @pilha_peek(ptr %pilha_ptr12)
  %1 = call i32 (ptr, ...) @printf(ptr @fmt_str.1, ptr @var_name_str.2, i32 %peeked_val13)
  ret i32 0
}

declare ptr @criar_pilha(i32)

declare void @pilha_push(ptr, i32)

declare i32 @pilha_peek(ptr)

declare void @pilha_set_topo(ptr, i32)

declare i32 @printf(ptr, ...)
