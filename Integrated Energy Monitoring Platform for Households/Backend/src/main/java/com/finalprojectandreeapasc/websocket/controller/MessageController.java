package com.finalprojectandreeapasc.websocket.controller;

import com.finalprojectandreeapasc.websocket.dto.MessageDTO;
import com.finalprojectandreeapasc.websocket.dto.ResponseDTO;
import org.springframework.messaging.handler.annotation.MessageMapping;
import org.springframework.messaging.handler.annotation.SendTo;
import org.springframework.stereotype.Controller;

import static com.finalprojectandreeapasc.UrlMapping.MESSAGE;
import static com.finalprojectandreeapasc.UrlMapping.SEND;

@Controller
public class MessageController {

    @MessageMapping(MESSAGE)
    @SendTo(SEND)
    public ResponseDTO getMessage(final MessageDTO message) throws InterruptedException {
        Thread.sleep(1000);

        return new ResponseDTO("MaxValue exceeded!");
    }
}
