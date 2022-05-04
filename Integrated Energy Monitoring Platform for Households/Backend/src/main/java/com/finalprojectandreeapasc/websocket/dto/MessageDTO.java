package com.finalprojectandreeapasc.websocket.dto;

import lombok.*;

@RequiredArgsConstructor
@Builder
@AllArgsConstructor
@Getter
@Setter
public class MessageDTO {
    private String message;
}