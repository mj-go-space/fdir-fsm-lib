# FDIR FSM Library

## 개요
이 리포지토리는 **FDIR (Fault Detection, Isolation, and Recovery)**  
상태기계(Finite State Machine) 기반의 위성 Fault 관리 모듈입니다.  
위성 시스템에서 발생하는 다양한 이상(Fault)을 탐지하고,  
자동 복구 루프를 수행하도록 설계되었습니다.  
NASA GSFC 및 KARI의 OBC Fault-Response 구조를 참고하여 작성되었습니다.

---

## Repository Structure
include/fdir.h # FSM structure & type definitions
src/fdir.c # Core FDIR logic implementation
tests/test_fsm.c # Unit test for state transitions
ci/github-actions.yml # CI build & test pipeline
