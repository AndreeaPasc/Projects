package com.finalprojectandreeapasc.user.controller;
import com.finalprojectandreeapasc.consumption.model.Consumption;
import com.finalprojectandreeapasc.device.model.Device;
import com.finalprojectandreeapasc.user.dto.UserListDTO;
import com.finalprojectandreeapasc.user.dto.UserMinimalDTO;
import com.finalprojectandreeapasc.user.service.UserService;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.*;

import java.util.List;

import static com.finalprojectandreeapasc.UrlMapping.*;

@RestController
@RequestMapping(USERS)
@RequiredArgsConstructor
public class UserController {

    private final UserService userService;

    @GetMapping
    public List<UserListDTO> allUsers() {
        return userService.allUsersForList();
    }

    @GetMapping(ENTITY)
    public List<Device> getDevices(@PathVariable Long id) {
        return userService.getDevices(id);
    }

    @PostMapping
    public UserMinimalDTO create(@RequestBody UserMinimalDTO user){
        return userService.create(user);
    }

    @PutMapping(ENTITY)
    public UserMinimalDTO update(@PathVariable Long id, @RequestBody UserMinimalDTO user) {
        return userService.update(id, user);
    }

    @GetMapping( "/measures" + ENTITY)
    public List<Consumption> getConsumption(@PathVariable Long id) {
        return userService.getConsumption(id);
    }

    @DeleteMapping(ENTITY)
    public void delete(@PathVariable Long id) {
        userService.delete(id);
    }
}
